/*
linked list header file

Copyright 2013 ZhiQiang Fan <aji.zqfan@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstddef>

struct ListNode {
  int val;
  ListNode * next;
  explicit ListNode(int x) : val(x), next(NULL) {}
};

ListNode * create_list(int arr[], int n);
void delete_list(ListNode * l);
void print_list(ListNode * l);

#endif
