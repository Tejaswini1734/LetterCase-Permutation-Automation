from typing import List

class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        res = []
        self.helper(list(s), 0, res)
        return res

    def helper(self, arr: List[str], index: int, res: List[str]):
        if index == len(arr):
            res.append("".join(arr))
            return
        
        if arr[index].isalpha():
            arr[index] = arr[index].lower()
            self.helper(arr, index + 1, res)

            arr[index] = arr[index].upper()
            self.helper(arr, index + 1, res)
        else:
            self.helper(arr, index + 1, res)
