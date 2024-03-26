class ListNode:
    def __init__(self, val=0):
        self.val = val
        self.next = None

def reverse_list(head):
    prev = None
    curr = head

    while curr:
        next_node = curr.next
        curr.next = prev
        prev = curr
        curr = next_node

    return prev

# Example usage
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = ListNode(5)

reversed_head = reverse_list(head)

# Print the reversed linked list
while reversed_head:
    print(reversed_head.val, end=" -> ")
    reversed_head = reversed_head.next
print("None")