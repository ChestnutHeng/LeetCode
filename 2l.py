# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        l3 = ListNode(0)
        
        while l1 is not None or l2 is not None :
            if l1 is not None and l2 is None:
                now = l1.val
                l1 = l1.next
            elif l1 is not None and l2 is not None:
                now = l1.val + l2.val
                l1 = l1.next
                l2 = l2.next
            elif l2 is not None and l1 is None:
                now = l2.val
                l2 = l2.next
            
            now = l3.val + now
            l3.val = now % 10
            np = ListNode(now//10)
            np.next = l3
            l3 = np
        if l3.val == 0:
            l3 = np.next
        
        l4 = ListNode(0)
        while l3.next:
            l4.val = l3.val
            node = ListNode(0)
            node.next = l4
            l4 = node
            l3 = l3.next
        l4.val = l3.val
        l3 = l4
        if l3.next is None:
            if l3.val > 9:
                nd = ListNode(l3.val%10)
                l3.val = l3.val // 10
                nd.next = l3
                l3 = nd
        return l3
        
