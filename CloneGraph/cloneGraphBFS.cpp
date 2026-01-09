#include <bits/stdc++.h>
using namespace std;

// -------------------- LeetCode-style Node --------------------
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() : val(0) {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(std::move(_neighbors)) {}
};

// -------------------- Your Solution (NO implementation here) --------------------
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> oldToNew;
        queue<Node*> q;
        oldToNew[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            for (Node* nei : cur->neighbors) {
                if (oldToNew.find(nei) == oldToNew.end()) {
                    oldToNew[nei] = new Node(nei->val);
                    q.push(nei);
                }
                oldToNew[cur]->neighbors.push_back(oldToNew[nei]);
            }
        }
        return oldToNew[node];
    }
};

// -------------------- Parsing helpers --------------------
// Parses LeetCode-like adjacency list string, e.g. [[2,4],[1,3],[2,4],[1,3]] or [[]] or [].
static vector<vector<int>> parseAdjList(const string& s) {
    string t;
    t.reserve(s.size());
    for (char c : s) if (!isspace(static_cast<unsigned char>(c))) t.push_back(c);

    if (t == "[]") return {};

    if (t.size() < 2 || t.front() != '[' || t.back() != ']')
        throw runtime_error("Invalid format: must start with '[' and end with ']'");

    vector<vector<int>> adj;
    int i = 0;

    auto expect = [&](char ch) {
        if (i >= (int)t.size() || t[i] != ch) {
            ostringstream oss;
            oss << "Parse error: expected '" << ch << "' at position " << i;
            throw runtime_error(oss.str());
        }
        ++i;
    };

    auto parseInt = [&]() -> int {
        if (i >= (int)t.size() || (!isdigit((unsigned char)t[i]) && t[i] != '-'))
            throw runtime_error("Parse error: expected integer");
        int sign = 1;
        if (t[i] == '-') { sign = -1; ++i; }
        long long val = 0;
        if (i >= (int)t.size() || !isdigit((unsigned char)t[i]))
            throw runtime_error("Parse error: invalid integer");
        while (i < (int)t.size() && isdigit((unsigned char)t[i])) {
            val = val * 10 + (t[i] - '0');
            ++i;
        }
        return (int)(sign * val);
    };

    expect('[');

    // Empty top-level list: []
    if (i < (int)t.size() && t[i] == ']') {
        expect(']');
        return {};
    }

    while (true) {
        // Each entry is a list: [...]
        expect('[');
        vector<int> row;

        // Empty row: []
        if (i < (int)t.size() && t[i] == ']') {
            expect(']');
        } else {
            while (true) {
                row.push_back(parseInt());
                if (i < (int)t.size() && t[i] == ',') { ++i; continue; }
                expect(']');
                break;
            }
        }

        adj.push_back(std::move(row));

        if (i < (int)t.size() && t[i] == ',') { ++i; continue; }
        expect(']');
        break;
    }

    if (i != (int)t.size())
        throw runtime_error("Parse error: trailing characters");

    return adj;
}

// -------------------- Graph build/serialize --------------------
// LeetCode convention for this problem: nodes labeled 1..n, adjacency list size n,
// adj[i] contains neighbors of node (i+1). Return pointer to node 1.
// For adjList = [[]], there is 1 node with no neighbors.
static Node* buildGraphFromAdj(const vector<vector<int>>& adj) {
    if (adj.empty()) return nullptr;

    int n = (int)adj.size();
    vector<Node*> nodes(n + 1, nullptr); // 1..n

    for (int i = 1; i <= n; ++i) nodes[i] = new Node(i);

    for (int i = 1; i <= n; ++i) {
        for (int v : adj[i - 1]) {
            if (v < 1 || v > n) throw runtime_error("Neighbor label out of range");
            nodes[i]->neighbors.push_back(nodes[v]);
        }
    }
    return nodes[1];
}

// Serialize reachable graph to adjacency list (by labels).
static vector<vector<int>> serializeGraphToAdj(Node* start) {
    if (!start) return {};

    unordered_set<Node*> vis;
    queue<Node*> q;

    q.push(start);
    vis.insert(start);

    int maxLabel = start->val;
    unordered_map<int, Node*> labelToNode;
    labelToNode[start->val] = start;

    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        maxLabel = max(maxLabel, cur->val);
        labelToNode[cur->val] = cur;

        for (Node* nei : cur->neighbors) {
            if (!nei) continue;
            maxLabel = max(maxLabel, nei->val);
            labelToNode[nei->val] = nei;
            if (!vis.count(nei)) {
                vis.insert(nei);
                q.push(nei);
            }
        }
    }

    vector<vector<int>> adj(maxLabel);
    for (int label = 1; label <= maxLabel; ++label) {
        if (!labelToNode.count(label)) continue;
        Node* node = labelToNode[label];
        for (Node* nei : node->neighbors) adj[label - 1].push_back(nei->val);
    }
    return adj;
}

static void printAdj(const vector<vector<int>>& adj) {
    cout << "[";
    for (size_t i = 0; i < adj.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < adj[i].size(); ++j) {
            cout << adj[i][j];
            if (j + 1 < adj[i].size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < adj.size()) cout << ",";
    }
    cout << "]";
}

// Verify that no node pointer in the cloned graph is also present in the original graph.
static bool deepCopyCheck(Node* orig, Node* clone) {
    if (!orig && !clone) return true;
    if (!orig || !clone) return false;

    auto collect = [](Node* start) {
        unordered_set<Node*> out;
        queue<Node*> q;
        q.push(start);
        out.insert(start);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            for (Node* nei : cur->neighbors) {
                if (nei && !out.count(nei)) {
                    out.insert(nei);
                    q.push(nei);
                }
            }
        }
        return out;
    };

    auto A = collect(orig);
    auto B = collect(clone);

    for (Node* p : B) {
        if (A.count(p)) return false;
    }
    return true;
}

static void runExample(const string& input) {
    cout << "\n========================================\n";
    cout << "Input:  adjList = " << input << "\n";

    auto adj = parseAdjList(input);
    Node* start = buildGraphFromAdj(adj);

    Solution sol;
    Node* cloned = sol.cloneGraph(start); // <-- your implementation

    auto origAdj = serializeGraphToAdj(start);
    auto cloneAdj = serializeGraphToAdj(cloned);

    cout << "Output (original serialized): ";
    printAdj(origAdj);
    cout << "\n";

    cout << "Output (clone serialized):    ";
    printAdj(cloneAdj);
    cout << "\n";

    cout << "Deep copy check: " << (deepCopyCheck(start, cloned) ? "PASS" : "FAIL") << "\n";
}

int main() {
    try {
        // LeetCode Example 1
        runExample("[[2,4],[1,3],[2,4],[1,3]]");

        // LeetCode Example 2
        runExample("[[]]");

        // LeetCode Example 3
        runExample("[]");
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
