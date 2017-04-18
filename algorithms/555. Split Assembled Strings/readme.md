Given a list of strings, you could assemble these strings together into a loop. Among all the possible loops, you need to find the lexicographically biggest string after cutting and making one breakpoint of the loop, which will make a looped string into a regular one.

So, to find the lexicographically biggest string, you need to experience two phases:

1. Assemble all the strings into a loop, where you can reverse some strings or not and connect them in the same order as given.
1. Cut and make one breakpoint in any place of the loop, which will make a looped string into a regular string starting from the character at the cutting point.

And your job is to find the lexicographically biggest one among all the regular strings.

Example:

~~~
Input: "abc", "xyz"
Output: "zyxcba"
Explanation: You can get the looped string "-abcxyz-", "-abczyx-", "-cbaxyz-", "-cbazyx-",
where '-' represents the looped status.
The answer string came from the fourth looped one,
where you could cut from the middle and get "zyxcba".
~~~

Note:

1. The input strings will only contain lowercase letters.
1. The total length of all the strings will not over 1000.
