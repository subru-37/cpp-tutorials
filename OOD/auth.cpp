#include <iostream>
#include <unordered_map>
#include <string>
#include <openssl/sha.h> // For SHA256 hashing

using namespace std;
class User {
private:
    string username;
    string passwordHash;
    string role;

    string hashPassword(const string& password) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, password.c_str(), password.size());
        SHA256_Final(hash, &sha256);

        string hashStr;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            char buffer[3];
            snprintf(buffer, sizeof(buffer), "%02x", hash[i]);
            hashStr += buffer;
        }
        return hashStr;
    }

public:
    User(const string& username, const string& password, const string& role)
        : username(username), passwordHash(hashPassword(password)), role(role) {}

    bool verifyPassword(const string& password) const {
        return passwordHash == hashPassword(password);
    }

    string getUsername() const {
        return username;
    }

    string getRole() const {
        return role;
    }
};

class Authenticator {
private:
    unordered_map<string, User> users;
    unordered_map<string, string> sessions;

    string createSession(const User& user) {
        string sessionId = user.getUsername(); // Simple session ID based on username
        sessions[sessionId] = user.getUsername();
        return sessionId;
    }

public:
    void registerUser(const string& username, const string& password, const string& role) {
        if (users.find(username) != users.end()) {
            throw runtime_error("User already exists.");
        }
        User user(username, password, role);
        users[username] = user;
        cout << "User " << username << " registered successfully.\n";
    }

    string login(const string& username, const string& password) {
        auto it = users.find(username);
        if (it != users.end() && it->second.verifyPassword(password)) {
            string sessionId = createSession(it->second);
            cout << "User " << username << " logged in successfully.\n";
            return sessionId;
        }
        throw runtime_error("Invalid username or password.");
    }

    void logout(const string& sessionId) {
        auto it = sessions.find(sessionId);
        if (it != sessions.end()) {
            cout << "User " << it->second << " logged out successfully.\n";
            sessions.erase(it);
        } else {
            throw runtime_error("Invalid session.");
        }
    }

    bool isLoggedIn(const string& sessionId) const {
        return sessions.find(sessionId) != sessions.end();
    }

    string getUserRole(const string& sessionId) const {
        auto it = sessions.find(sessionId);
        if (it != sessions.end()) {
            return users.at(it->second).getRole();
        }
        throw runtime_error("Invalid session.");
    }
};

int main() {
    Authenticator authenticator;

    try {
        // Register users
        authenticator.registerUser("alice", "password123", "member");
        authenticator.registerUser("bob", "securepassword", "admin");

        // Login and authenticate
        string sessionIdAlice = authenticator.login("alice", "password123");
        string sessionIdBob = authenticator.login("bob", "securepassword");

        // Check login status and roles
        cout << boolalpha << authenticator.isLoggedIn(sessionIdAlice) << "\n";  // true
        cout << authenticator.getUserRole(sessionIdBob) << "\n";  // admin

        // Logout
        authenticator.logout(sessionIdAlice);
        cout << boolalpha << authenticator.isLoggedIn(sessionIdAlice) << "\n";  // false
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
