class ListNode:
    def __init__(self, val=0):
        self.val = val
        self.next = None

def has_cycle(head):
    if not head or not head.next:
        # No cycle if the list is empty or has only one node
        return False

    slow = head
    fast = head

    while fast and fast.next:
        slow = slow.next       # Move slow pointer by one step
        fast = fast.next.next  # Move fast pointer by two steps

        if slow == fast:
            # If slow and fast pointers meet, there is a cycle
            return True

    return False

# Example usage
head1 = ListNode(3)
head1.next = ListNode(2)
head1.next.next = ListNode(0)
head1.next.next.next = ListNode(-4)
head1.next.next.next.next = head1.next  # Create a cycle

head2 = ListNode(1)
head2.next = ListNode(2)

print("Example 1 (has cycle):", has_cycle(head1))  # Output: True
print("Example 2 (has cycle):", has_cycle(head2))  # Output: False
print("Example 3 (no cycle):", has_cycle(ListNode(1)))  