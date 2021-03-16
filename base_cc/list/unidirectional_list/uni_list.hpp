#pragma once

namespace uni_list {
template <typename ValTp> struct ulist_node {
  ValTp value;
  ulist_node<ValTp> *next;
  ulist_node(ValTp val, ulist_node<ValTp> *nx) : value(val), next(nx) {}
  ulist_node(ValTp val) : ulist_node(val, nullptr) {}
};

template <typename ValTp, typename ItTp>
ulist_node<ValTp> *make_ulist(ItTp beg__, ItTp end__) {
  ulist_node<ValTp> iHead(0);
  ulist_node<ValTp> *p = &iHead;

  for (auto it = beg__; it != end__; it++) {
    p->next = new ulist_node<ValTp>(*beg__);
    p = p->next;
  }
  return iHead.next;
}

template <typename ValTp>
bool has_ring(ulist_node<ValTp> *root, int &meet_pos) {
  meet_pos = 0;
  if (root == nullptr) {
    return false;
  }
  auto slow = root;
  auto fast = root;
  while (true) {
    if (!fast) {
      break;
    }
    meet_pos += 1;
    fast = fast->next;
    slow = slow->next;
    if (!fast) {
      break;
    }
    fast = fast->next;
    if (fast == slow) {
      return true;
    }
  }
  return false;
}

template <typename ValTp> bool has_ring(ulist_node<ValTp> *root) {
  int meet_pos;
  return has_ring(root, meet_pos);
}
template <typename ValTp>
ulist_node<ValTp> *tail_ulist(ulist_node<ValTp> *root, int &list_len) {
  int meet_pos = 0;
  if (has_ring(root, meet_pos)) {
  } else {
    auto tail_ = root;
    for (; tail_->next; tail_ = tail_->next) {
      list_len += 1;
    }
    return tail_;
  }
}

template <typename ValTp> void release_ulist(ulist_node<ValTp> *root) {
  auto p = root;
  decltype(root) nx = nullptr;
  while (p) {
    nx = p->next;
    delete p;
    p = nx;
  }
}
} // namespace uni_list
