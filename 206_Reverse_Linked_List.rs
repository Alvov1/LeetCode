#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}

impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head == None || head.as_ref().unwrap().next == None { return head; }

        let mut head = head.unwrap();
        let mut tail = head.next.as_ref().unwrap().clone();
        head.next = None;

        while tail.next != None {
            let temp = tail.next.as_ref().unwrap().clone();
            tail.next = Some(head.clone());
            head = tail;
            tail = temp;
        }
        tail.next = Some(head.clone());
        Some(tail)
    }
}