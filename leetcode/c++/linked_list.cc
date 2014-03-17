/*
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
#include "linked_list.h"
#include <cstdio>

ListNode * create_list(int arr[], int n) {
  ListNode * head = NULL;
  ListNode * cur = NULL;

  if (n < 1)
    return NULL;
  cur = head = new ListNode(arr[0]);
  for (int i = 1; i < n; i++) {
    cur->next = new ListNode(arr[i]);
    cur = cur->next;
  }
  return head;
}

void delete_list(ListNode * l) {
  ListNode * cur = NULL;
  while (l) {
    cur = l;
    l = l->next;
    delete cur;
  }
}

void print_list(ListNode * l) {
  ListNode * cur = l;
  while (cur) {
    printf("%d ", cur->val);
    cur = cur->next;
  }
  printf("\n");
}
