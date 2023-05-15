#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int x, y;
  int cost;
  Node* parent;

  Node(int x, int y, int cost, Node* parent) :
    x(x), y(y), cost(cost), parent(parent) {}
};

int heuristic(Node* node, Node* goal) {
  return abs(node->x - goal->x) + abs(node->y - goal->y);
}

void astar(vector<vector<bool>> &grid, int startX, int startY, int goalX, int goalY) {
  // Create a priority queue to store the nodes that have been visited.
  priority_queue<Node, vector<Node>, greater<Node>> pq;

  // Add the start node to the priority queue.
  pq.push(Node(startX, startY, 0, nullptr));

  // While the priority queue is not empty...
  while (!pq.empty()) {
    // Get the node with the lowest f-cost from the priority queue.
    Node* currentNode = pq.top();
    pq.pop();

    // If the current node is the goal node...
    if (currentNode->x == goalX && currentNode->y == goalY) {
      // Print the path from the start node to the goal node.
      while (currentNode != nullptr) {
        cout << "(" << currentNode->x << ", " << currentNode->y << ") ";
        currentNode = currentNode->parent;
      }
      cout << endl;
      return;
    }

    // For each neighbor of the current node...
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        // If the neighbor is within the bounds of the grid...
        if (0 <= currentNode->x + i && currentNode->x + i < grid.size() &&
            0 <= currentNode->y + j && currentNode->y + j < grid[0].size() &&
            !grid[currentNode->x + i][currentNode->y + j]) {
          // Create a new node for the neighbor.
          Node* neighbor = new Node(currentNode->x + i, currentNode->y + j,
                                    currentNode->cost + 1, currentNode);

          // Add the neighbor to the priority queue.
          pq.push(neighbor);
        }
      }
    }
  }
}

int main() {
  // Create a 2D grid.
  vector<vector<bool>> grid(10, vector<bool>(10));

  // Add some obstacles to the grid.
  grid[0][0] = true;
  grid[0][1] = true;
  grid[1][0] = true;
  grid[2][2] = true;
  grid[3][3] = true;
  grid[4][4] = true;

  // Start and goal positions.
  int startX = 0;
  int startY = 0;
  int goalX = 9;
  int goalY = 9;

  // Run the AO* search algorithm.
  astar(grid, startX, startY, goalX, goalY);

  return 0;
}
