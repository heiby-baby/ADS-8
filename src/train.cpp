// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  countOp = 0;
  first = nullptr;
}

void Train::addCage(bool light) {
  Cage* cur = new Cage;
  cur->light = light;
  if (first == nullptr) {
    first = cur;
    first->prev = first;
    first->next = first;
  } else {
    cur->next = first;
    cur->prev = first->prev;
    first->prev->next = cur;
    first->prev = cur;
  }
}

int Train::getLength() {
  int  Dynamic_counter = 1;
  Cage* cur = first;
  if (cur == nullptr) return 0;
  cur->light = true;
  countOp++;
  cur = cur->next;
  while (cur) {
    if (cur->light == false) {
      Dynamic_counter++;
      countOp++;
      cur = cur->next;
    } else {
      cur->light = false;
      for (int i = 0; i < Dynamic_counter; i++) {
        countOp++;
        cur = cur->prev;
      }
      if (cur->light == false) {
        return Dynamic_counter;
      } else {
        Dynamic_counter = 1;
        countOp++;
        cur = cur->next;
      }
    }
  }
  return 0;
}
