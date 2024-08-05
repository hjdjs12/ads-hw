#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <cstdint>
// #include <optional>
// #include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <random>

namespace skiplist
{

	using key_type = uint64_t;
	// using value_type = std::vector<char>;
	using value_type = std::string;

	class skiplist_type
	{
	public:
		// add something here
		struct skiplist_node
		{
		public:
			key_type key;
			value_type value;
			skiplist_node *next;
			skiplist_node *prev;
			skiplist_node *above;
			skiplist_node *below;
			skiplist_node() : key(-1), value(""), next(nullptr), prev(nullptr), above(nullptr), below(nullptr){};
			skiplist_node(key_type key_data, value_type value_data, skiplist_node *next1, skiplist_node *prev1, skiplist_node *above1, skiplist_node *below1) : key(key_data), value(value_data), next(next1), prev(prev1), above(above1), below(below1) {}
		};
		skiplist_node *head;
		skiplist_node *tail;
		int size;
		int maxLevel;
		int currentLevel;
		double prob;
		int node_length;
		// 随机高度
		int randomLevel() const
		{
			int i = 1;
			while (rand() / (float)RAND_MAX < prob)
			{
				i++;
			}
			return i;
		}

		skiplist_node *find_lt(skiplist_node *base)
		{
			while (!head_node(base))
			{
				base = base->prev;
				if (base->above != nullptr)
				{
					break;
				}
			}
			return base->above;
		}
		skiplist_node *find_rt(skiplist_node *base)
		{
			while (!tail_node(base))
			{
				base = base->next;
				if (base->above != nullptr)
				{
					break;
				}
			}
			return base->above;
		};
		void updateLevel(int build)
		{
			int i = build - currentLevel;
			while (i-- > 0)
			{
				head->above = new skiplist_node();
				skiplist_node *tmp = head;
				head = head->above;
				head->below = tmp;
				tail->above = new skiplist_node();
				tmp = tail;
				tail = tail->above;
				tail->below = tmp;
			}
		};
		bool head_node(skiplist_node *base) const;
		bool tail_node(skiplist_node *base) const;
		explicit skiplist_type(double p = 0.5, int element_count = 0);
		void put(key_type key, const value_type &val);
		// std::optional<value_type> get(key_type key) const;
		std::string get(key_type key);

		// for hw1 only
		int query_distance(key_type key);
	};

} // namespace skiplist

#endif // SKIPLIST_H
