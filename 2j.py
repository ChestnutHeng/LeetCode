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
        
        #result = None
        result = None
        prev = None
        carry = 0
        #  Differ:
        #  [0] + [1 2]?
        while l1 is not None or l2 is not None or carry != 0:
            if l1 is None:
                n1 = 0
            else:
                n1 = l1.val
                l1 = l1.next
            if l2 is None:
                n2 = 0
            else:
                n2 = l2.val
                l2 = l2.next
            current = n1 + n2 + carry
            if current >= 10:
                carry = 1
                current %= 10
            else:
                carry = 0
            node = ListNode(current)
            if prev is None:
#                prev = node
                result = node
            else:
                prev.next = node
            prev = node
#            rlist.append(ListNode(current))
        
#        for idx in range(0, len(rlist) - 1):
#            rlist[idx].next = rlist[idx + 1]
        
#        return rlist[0]
        return result
            
        
        
        
        
