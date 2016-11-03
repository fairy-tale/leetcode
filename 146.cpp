//using double-linked list to store. 
//use hash map to find the iterator, then delete each element in the list is O(1)
class LRUCache{
private:
	int c;
	//c++ stl list is a double-linked list
	//http://www.cplusplus.com/reference/list/list/
	//map<int, iterator> is used to find each element in list in O(1)
	unordered_map<int, list<pair<int, int>>::iterator> hash;
	list<pair<int, int>> link;

	void up(int key) {
		//use *iterator to get the value of iterator!
		pair<int, int> t = *hash[key];
		link.erase(hash[key]);
		link.push_front(t);
		hash[key] = link.begin();
	}
public:
	LRUCache(int capacity) {
		c = capacity;
	}

	int get(int key) {
		if (!hash.count(key)) {
			return -1;
		}
		else {
			up(key);
			//for iterator, use ->second !  can't use .second
			return link.begin()->second;
		}
	}

	void set(int key, int value) {
		if (hash.count(key)) {
			up(key);
			link.begin()->second = value;
		}
		else {
			if (c == link.size()) {
				hash.erase(link.rbegin()->first);
				link.pop_back();
			}
			link.push_front(make_pair(key, value));
			hash[key] = link.begin();
		}
	}
};