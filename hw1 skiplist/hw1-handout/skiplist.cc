#include "skiplist.h"
#include <optional>

namespace skiplist
{

    skiplist_type::skiplist_type(double p, int element_count)
    {

        head = new skiplist_node();
        tail = new skiplist_node();
        head->next = tail;
        tail->prev = head;
        size = element_count;
        // maxLevel = (element_count >= 1 / p) ? (int)(log(element_count) / log(1 / p)) : 1;
        prob = p;
        currentLevel = 1;
        node_length = 2;
        // skiplist_node *tmp1 = head;
        // skiplist_node *tmp2 = tail;
        // skiplist_node *tmp3 = head;
        // skiplist_node *tmp4 = tail;
        // for (int i = 1; i < maxLevel; i++)
        // {
        //     tmp1->below = new skiplist_node();
        //     tmp2->below = new skiplist_node();
        //     tmp1 = tmp1->below;
        //     tmp2 = tmp2->below;
        //     tmp1->above = tmp3;
        //     tmp2->above = tmp4;
        //     tmp1->next = tmp2;
        //     tmp2->prev = tmp1;
        //     tmp3 = tmp1;
        //     tmp4 = tmp2;
        // }
    }
    void skiplist_type::put(key_type key, const value_type &val)
    {
        skiplist_node *start = head;
        skiplist_node *end = start->next;
        int build_level = randomLevel();
        for (int i = currentLevel; i > 1; i--)
        {
            while (end->key < key && !tail_node(end))
            {
                start = start->next;
                end = end->next;
            }
            start = start->below;
            end = start->next;
        }
        while (end->key < key && !tail_node(end))
        {
            start = start->next;
            end = end->next;
        }
        if (end->key == key)
        {
            end->value = val;
            while (end->above != nullptr)
            {
                end = end->above;
                end->above->value = val;
            }
        }
        else
        {
            skiplist_node *a = new skiplist_node(key, val, end, start, nullptr, nullptr);
            start->next = a;
            end->prev = a;
            if (build_level > currentLevel)
            {
                updateLevel(build_level);
            }
            for (int i = 1; i < build_level; i++)
            {
                skiplist_node *left = find_lt(a);
                skiplist_node *right = find_rt(a);
                a->above = new skiplist_node(key, val, right, left, nullptr, a);
                a = a->above;
                left->next = a;
                right->prev = a;
            }
            currentLevel = (currentLevel >= build_level) ? currentLevel : build_level;
        }
    }

    std::string skiplist_type::get(key_type key)
    {
        bool isFound = false;
        skiplist_node *start = head;
        skiplist_node *end = start->next;
        for (int i = currentLevel; i > 1; i--)
        {
            while (end->key < key && !tail_node(end))
            {

                start = start->next;
                end = end->next;
                node_length++;
            }
            if (end->key == key)
            {
                isFound = true;
                break;
            }
            start = start->below;
            end = start->next;
            node_length++;
        }
        if (isFound)
        {
            return end->value;
        }
        while (end->key < key && !tail_node(end))
        {

            start = start->next;
            end = end->next;
            node_length++;
        }
        return end->value;
    }
    int skiplist_type::query_distance(key_type key)
    {
        get(key);
        int a = node_length;
        node_length = 2;
        return a;
    }

    bool skiplist_type::head_node(skiplist_node *base) const
    {
        skiplist_node *tmp = head;
        if (base == tmp)
        {
            return true;
        }

        while (tmp->below != nullptr)
        {
            tmp = tmp->below;
            if (base == tmp)
            {
                return true;
            }
        }
        return false;
    }
    bool skiplist_type::tail_node(skiplist_node *base) const
    {
        skiplist_node *tmp = tail;
        if (base == tmp)
        {
            return true;
        }
        while (tmp->below != nullptr)
        {
            tmp = tmp->below;
            if (base == tmp)
            {
                return true;
            }
        }
        return false;
    }

} // namespace skiplist
