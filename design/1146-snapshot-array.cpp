// 1146. Snapshot Array
// https://leetcode.com/problems/snapshot-array/
// Difficulty: Medium
// Topics: Array, Hash Table, Design, Binary Search
//
// Implement a SnapshotArray that supports the following interface:
//   SnapshotArray(int length) initializes an array-like data structure with the
//     given length. Initially, each element equals 0.
//   void set(index, val) sets the element at the given index to be equal to val.
//   int snap() takes a snapshot of the array and returns the snap_id: the total
//     number of times we called snap() minus 1.
//   int get(index, snap_id) returns the value at the given index, at the time
//     we took the snapshot with the given snap_id.

class SnapshotArray {
private:
    int snapId = 0;
    vector<vector<pair<int, int>>>arr;

public:
    SnapshotArray(int length) {
        arr = vector<vector<pair<int, int>>>(length);
        snapId = 0;
    }
    
    void set(int index, int val) {
        if(arr[index].size() == 0)
        {
            arr[index].push_back({snapId, val});
        }
        else
        {
            int size = arr[index].size();
            if(arr[index][size-1].first == snapId)
            {
                arr[index][size-1].second = val;
            }
            else
                arr[index].push_back({snapId, val});
        }
    }
    
    int snap() {
        snapId += 1;
        return snapId-1;
    }
    
    int get(int index, int snap_id) {
        if(arr[index].size() == 0)
            return 0;
        int low = 0, high = arr[index].size()-1;
        int res = 0;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[index][mid].first == snap_id)
                return arr[index][mid].second;
            else if(arr[index][mid].first < snap_id)
            {
                res = arr[index][mid].second;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return res;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */