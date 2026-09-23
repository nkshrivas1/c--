#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, y;
};

// Node structure for the Doubly Linked List
struct Node {
    Point p;
    Node* prev;
    Node* next;
    Node(Point point) : p(point), prev(nullptr), next(nullptr) {}
};

// Global point needed for polar angle sorting
Point pivot;

// Helper to calculate squared distance
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Determines triplet cross: 0 -> Collinear, 1 -> Clockwise, 2 -> Counter-clockwise
int cross(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

// Comparator to sort points by polar angle with respect to pivot
bool compare(Point p1, Point p2) {
    int o = cross(pivot, p1, p2);
    if (o == 0) {
        return distSq(pivot, p1) < distSq(pivot, p2);
    }
    return (o == 2);
}

// Function to delete a node from the doubly linked list
void deleteNode(Node* curr) {
    if (!curr) return;
    if (curr->prev) curr->prev->next = curr->next;
    if (curr->next) curr->next->prev = curr->prev;
    delete curr;
}

// Cleans up memory at the end of the program
void freeList(Node* head) {
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
}

void grahamScanDLL(std::vector<Point>& points) {
    int n = points.size();
    if (n < 3) {
        std::cout << "Convex Hull not possible with less than 3 points.\n";
        return;
    }

    // Step 1: Find the bottom-leftmost point as the pivot
    int min_idx = 0;
    for (int i = 1; i < n; i++) {
        if ((points[i].y < points[min_idx].y) || 
            (points[i].y == points[min_idx].y &&
                 points[i].x < points[min_idx].x)) {
            min_idx = i;
        }
    }
    std::swap(points[0], points[min_idx]);

    // Step 2: Sort based on polar angle
    pivot = points[0];
    std::sort(points.begin() + 1, points.end(), compare);

    // Filter out redundant collinear points with the same angle
    int m = 1;
    for (int i = 1; i < n; i++) {
        while (i < n - 1 && cross(pivot, points[i], points[i + 1]) == 0) {
            i++;
        }
        points[m++] = points[i];
    }
    if (m < 3) return;

    // Step 3: Build the initial Doubly Linked List with the first 3 points
    Node* head = new Node(points[0]);
    Node* second = new Node(points[1]);
    Node* curr = new Node(points[2]);

    head->next = second;
    second->prev = head;
    second->next = curr;
    curr->prev = second;

    // Step 4: Scan the remaining elements
    for (int i = 3; i < m; i++) {
        // While the current configuration causes a right turn (not a strictly left turn)
        while (curr->prev && cross(curr->prev->p,
             curr->p, points[i]) != 2) {
            Node* temp = curr;
            curr = curr->prev; // Step back
            deleteNode(temp);  // Remove the right-turn point in O(1)
        }

        // Add the new point to the list
        Node* newNode = new Node(points[i]);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode; // Advance forward
    }

    // Output the resulting convex hull points
    std::cout << "The points in the Convex Hull are:\n";
    Node* temp = head;
    while (temp) {
        std::cout << "(" << temp->p.x << ", " << temp->p.y << ")\n";
        temp = temp->next;
    }

    // Free allocated memory
    freeList(head);
}

int main() {
    std::vector<Point> points = {
        {0, 3}, {1, 1}, {2, 2}, {4, 4},
        {0, 0}, {1, 2}, {3, 1}, {3, 3}
    };

    grahamScanDLL(points);
    return 0;
}
