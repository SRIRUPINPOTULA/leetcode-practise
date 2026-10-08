// 3408. Design Task Manager
// https://leetcode.com/problems/design-task-manager/
// Difficulty: Medium
// Topics: Hash Table, Design, Heap (Priority Queue), Set
//
// There is a task management system that allows users to manage their tasks,
// each associated with a priority. The system should efficiently handle adding,
// modifying, executing, and removing tasks.
//
// Implement the TaskManager class:
//   TaskManager(vector<vector<int>>& tasks) initializes the task manager with a
//     list of user-task-priority triples. Each element in the input list is of
//     the form [userId, taskId, priority], which adds a task to the specified
//     user with the given priority.
//   void add(int userId, int taskId, int priority) adds a task with the
//     specified taskId and priority to the user with userId. It is guaranteed
//     that taskId does not exist in the system.
//   void edit(int taskId, int newPriority) updates the priority of the existing
//     taskId to newPriority. It is guaranteed that taskId exists in the system.
//   void rmv(int taskId) removes the task identified by taskId from the system.
//     It is guaranteed that taskId exists in the system.
//   int execTop() executes the task with the highest priority across all users.
//     If there are multiple tasks with the same highest priority, execute the
//     one with the highest taskId. After executing, the taskId is removed from
//     the system. Return the userId associated with the executed task. If no
//     tasks are available, return -1.
//
// Note that a user may be assigned multiple tasks.

class TaskManager {
private:
    struct ListNode {
        int userID;
        int priority;
        ListNode(int u, int p){
            userID = u;
            priority = p;
        }   
    };
    unordered_map<int, ListNode*>tasksList;
    map<int, set<int>>priorityList;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for(int i = 0; i < tasks.size(); i++)
        {
            vector<int>temp = tasks[i];
            ListNode *newNode = new ListNode(temp[0], temp[2]);
            tasksList[temp[1]] = newNode;
            priorityList[temp[2]].insert(temp[1]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        ListNode *newNode = new ListNode(userId, priority);
        priorityList[priority].insert(taskId);
        tasksList[taskId] = newNode;
    }
    
    void edit(int taskId, int newPriority) {
        ListNode* oldNode = tasksList[taskId];
        priorityList[oldNode->priority].erase(taskId);
        priorityList[newPriority].insert(taskId);
        if(priorityList[oldNode->priority].empty() == true)
            priorityList.erase(oldNode->priority);
        oldNode->priority = newPriority;
    }
    
    void rmv(int taskId) {
        ListNode *node = tasksList[taskId];
        int oldPriority = tasksList[taskId]->priority;
        if(priorityList[oldPriority].size() == 1)
        {
            priorityList.erase(oldPriority);
        }
        else
        {
            priorityList[oldPriority].erase(taskId);
        }
        tasksList.erase(taskId);
        delete node;
    }
    
    int execTop() {
        int userId = -1;
        if(priorityList.empty() == true)
            return -1;

        auto a = priorityList.end();
        a--;
        int task = 0;
        auto pointer = a->second.end();
        pointer--;
        task = *pointer;
        if( a->second.size() == 1)
            priorityList.erase(a);
        else
            priorityList[a->first].erase(task);
        userId= tasksList[task]->userID;
        delete tasksList[task];
        tasksList.erase(task);
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */