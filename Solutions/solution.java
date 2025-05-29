package Solutions;

import java.util.*;


public class solution {
    public List<String> letterCasePermutation(String s) {
        List<String> res = new ArrayList<>();
        helper(s.toCharArray(), 0, res);
        return res;
    }

    private void helper(char[] chArr, int index, List<String> res) {
        if (index == chArr.length) {
            res.add(new String(chArr));
            return;
        }

        if (Character.isLetter(chArr[index])) {
            chArr[index] = Character.toLowerCase(chArr[index]);
            helper(chArr, index + 1, res);

            chArr[index] = Character.toUpperCase(chArr[index]);
            helper(chArr, index + 1, res);
        } else {
            helper(chArr, index + 1, res);
        }
    }
}
