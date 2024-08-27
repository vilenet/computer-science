#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;

class TimeMap {
private:
    std::unordered_map<std::string, std::map<int, std::string>> m;

public:
    TimeMap() {}

    void set(const std::string& key, const std::string& value, int timestamp) {
        m[key][timestamp] = value;
    }

    std::string get(const std::string& key, int timestamp) {
        if (m.find(key) == m.end()) {
            return "";
        }

        auto it = m[key].upper_bound(timestamp);

        if (it == m[key].begin()) {
            return "";
        }

        --it;
        return it->second;
    }
};

int main() {
    
    TimeMap timeMap = TimeMap();
    timeMap.set("foo", "bar", 1);                // store the key "foo" and value "bar" along with timestamp = 1.
    cout << timeMap.get("foo", 1); cout << endl; // return "bar"
    cout << timeMap.get("foo", 3); cout << endl; // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
    timeMap.set("foo", "bar2", 4);               // store the key "foo" and value "bar2" along with timestamp = 4.
    cout << timeMap.get("foo", 4); cout << endl; // return "bar2"
    cout << timeMap.get("foo", 5); cout << endl; // return "bar2"

    return 0;
}
