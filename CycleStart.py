class ListNode:
    def __init__(self, val=0):
        self.val = val
        self.next = None

def detect_cycle(head):
    if not head or not head.next:
        # No cycle if the list is empty or has only one node
        return None

    slow = head
    fast = head

    # Detect cycle using Floyd's Cycle-Finding Algorithm
    while fast and fast.next:
        slow = slow.next       # Move slow pointer by one step
        fast = fast.next.next  # Move fast pointer by two steps

        if slow == fast:
            # If slow and fast pointers meet, there is a cycle
            break
    else:
        # No cycle
        return None

    # Move one pointer to the head and keep the other at the meeting point
    slow = head
    while slow != fast:
        slow = slow.next
        fast = fast.next

    # Return the node where the cycle begins
    return slow

# Example usage
head1 = ListNode(3)
head1.next = ListNode(2)
head1.next.next = ListNode(0)
head1.next.next.next = ListNode(-4)
head1.next.next.next.next = head1.next  # Create a cycle

head2 = ListNode(1)
head2.next = ListNode(2)

print("Example 1 (cycle begins at index):", detect_cycle(head1).val)  # Output: 2
print("Example 2 (cycle begins at index):", detect_cycle(head2))  # Output: None (no cycle)
print("Example 3 (no cycle):", detect_cycle(ListNode(1)))  # Output: None (no cycle)