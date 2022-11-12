package Stack.StackLL;

public class CountParanthaseses {
    String str;

    public CountParanthaseses(String str)
    {
        this.str = str;
    }

    public boolean isBalance()
    {
        StackLinkList stack = new StackLinkList();
        int i = 0;
        while (i < str.length())
        {
            char c = str.charAt(i++);
            if (c == '{')
                stack.push('{');
            else if (c == '}')
            {
                if (!stack.isEmpty())
                    // char openBrace = (char)stack.pop();
                    stack.pop();
                    // Character openBrace = (Character)stack.pop();
                else
                {
                    System.out.println("this string is not balance by parantheses");
                    return false;
                }
            }
        }
        return true;
    }
}
