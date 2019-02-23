package Stack;

import java.util.Stack;
public class InfixToPostFix {

    static int Preference(char ch){
        switch (ch){
            case '-':
            case '+':
                return 1;
            case '*':
            case '/':
                return 2;
            case '^':
                return 3;
            default:
                return -1;
        }
    }
    static String infix2postFix(String exp){
        String result=new String("");
        Stack<Character> operandStack=new Stack<>();
        for(int i=0;i<exp.length();i++){
            char c=exp.charAt(i);
            if(Character.isLetterOrDigit(c)){
                result+=c;
            }
            else if(c=='('){
                operandStack.push('(');
            }
            else if(c==')'){
                while(!operandStack.isEmpty()&&operandStack.peek()!='('){
                    result+=operandStack.peek();
                    operandStack.pop();
                }
                if(!operandStack.isEmpty()&&operandStack.peek()=='(')
                    operandStack.pop();
            }
            else {

                    while( (!operandStack.isEmpty())&&(Preference(c)<=Preference(operandStack.peek()))){
                            result+=operandStack.peek();
                        operandStack.pop();
                    }
                    operandStack.push(c);
            }
        }
        while (!operandStack.isEmpty()){
            result+=operandStack.pop();
        }
        return result;
    }
    public static void main(String args[]){
        String exp = "a+b*(c^d-e)^(f+g*h)-i";
        System.out.printf(infix2postFix(exp));
    }
}
