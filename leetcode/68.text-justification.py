#
# @lc app=leetcode id=68 lang=python3
#
# [68] Text Justification
#
# https://leetcode.com/problems/text-justification/description/
#
# algorithms
# Hard (22.98%)
# Likes:    383
# Dislikes: 1057
# Total Accepted:    100.4K
# Total Submissions: 423.2K
# Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
#
# Given an array of words and a width maxWidth, format the text such that each
# line has exactly maxWidth characters and is fully (left and right)
# justified.
#
# You should pack your words in a greedy approach; that is, pack as many words
# as you can in each line. Pad extra spaces ' ' when necessary so that each
# line has exactly maxWidth characters.
#
# Extra spaces between words should be distributed as evenly as possible. If
# the number of spaces on a line do not divide evenly between words, the empty
# slots on the left will be assigned more spaces than the slots on the right.
#
# For the last line of text, it should be left justified and no extra space is
# inserted between words.
#
# Note:
#
#
# A word is defined as a character sequence consisting of non-space characters
# only.
# Each word's length is guaranteed to be greater than 0 and not exceed
# maxWidth.
# The input array words contains at least one word.
#
#
# Example 1:
#
#
# Input:
# words = ["This", "is", "an", "example", "of", "text", "justification."]
# maxWidth = 16
# Output:
# [
# "This    is    an",
# "example  of text",
# "justification.  "
# ]
#
#
# Example 2:
#
#
# Input:
# words = ["What","must","be","acknowledgment","shall","be"]
# maxWidth = 16
# Output:
# [
# "What   must   be",
# "acknowledgment  ",
# "shall be        "
# ]
# Explanation: Note that the last line is "shall be    " instead of "shall
# be",
# because the last line must be left-justified instead of fully-justified.
# ⁠            Note that the second line is also left-justified becase it
# contains only one word.
#
#
# Example 3:
#
#
# Input:
# words =
# ["Science","is","what","we","understand","well","enough","to","explain",
# "to","a","computer.","Art","is","everything","else","we","do"]
# maxWidth = 20
# Output:
# [
# "Science  is  what we",
# ⁠ "understand      well",
# "enough to explain to",
# "a  computer.  Art is",
# "everything  else  we",
# "do                  "
# ]
#
#
#

from typing import List


class Solution:
    @staticmethod
    def words_to_line(words, words_length, maxWidth):
        if len(words) == 1:
            line = f"{words[0]:<{maxWidth}}"
            # usage of f-strings: https://www.python.org/dev/peps/pep-0498/
        else:
            div, mod = divmod(maxWidth - words_length, len(words) - 1)
            line = words[0]
            for word in words[1:]:
                sep = ' ' * div
                if mod > 0:
                    sep += ' '
                    mod -= 1
                line += sep + word
        return line

    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        result = list()
        line_words = list()
        words_length = 0
        for word in words:
            # select words in a greedy way
            if words_length + len(word) + len(line_words) > maxWidth:
                result.append(self.words_to_line(
                    line_words, words_length, maxWidth))
                line_words.clear()
                words_length = 0
            line_words.append(word)
            words_length += len(word)

        if words_length > 0:
            # the last row
            result.append(f"{{:<{maxWidth}}}".format(' '.join(line_words)))

        return result


def main():
    words = ["Science", "is", "what", "we", "understand", "well", "enough", "to",
             "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"]
    solu = Solution()
    print('\n'.join(solu.fullJustify(words, 20)))

    words = ["This", "is", "an", "example", "of", "text", "justification."]
    print('\n'.join(solu.fullJustify(words, 16)))

    words = []
    print(solu.fullJustify(words, 16))


if __name__ == "__main__":
    main()
