import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Calculator implements ActionListener {
    JFrame frame;
    JTextField textField;
    JButton[] buttons = new JButton[10];
    JButton[] functionsB = new JButton[9];
    JButton b0, b1, b2, b3, b4, b5, b6, b7, b8, b9;
    JButton addB, subB, multiB, divB, pm;
    JButton clearB, delB, equalB, comaB;

    Font font = new Font("Arial", Font.BOLD, 20);

    double num1 = 0, num2 = 0;
    char operator = ' ';
    boolean isFirstNumber = true;

    Calculator() {
        frame = new JFrame("Calculator");

        textField = new JTextField();
        textField.setBounds(0, 0, 400, 100);
        textField.setFont(new Font("Arial", Font.BOLD, 50));
        textField.setHorizontalAlignment(JTextField.RIGHT);
        textField.setEditable(false);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 630);
        frame.setLayout(null);
        frame.add(textField);

        b0 = new JButton("0");
        b1 = new JButton("1");
        b2 = new JButton("2");
        b3 = new JButton("3");
        b4 = new JButton("4");
        b5 = new JButton("5");
        b6 = new JButton("6");
        b7 = new JButton("7");
        b8 = new JButton("8");
        b9 = new JButton("9");

        addB = new JButton("+");
        subB = new JButton("−");
        multiB = new JButton("×");
        divB = new JButton("÷");
        equalB = new JButton("=");
        clearB = new JButton("AC");
        delB = new JButton("⇦");
        comaB = new JButton(".");
        pm = new JButton("¬");

        functionsB[0] = addB;
        functionsB[1] = subB;
        functionsB[2] = multiB;
        functionsB[3] = divB;
        functionsB[4] = equalB;
        functionsB[5] = clearB;
        functionsB[6] = delB;
        functionsB[7] = comaB;
        functionsB[8] = pm;

        buttons[0] = b0;
        buttons[1] = b1;
        buttons[2] = b2;
        buttons[3] = b3;
        buttons[4] = b4;
        buttons[5] = b5;
        buttons[6] = b6;
        buttons[7] = b7;
        buttons[8] = b8;
        buttons[9] = b9;

        for (int i = 0; i < 9; i++) {
            functionsB[i].addActionListener(this);
            functionsB[i].setFont(font);
            functionsB[i].setFocusable(false);
        }

        for (int i = 0; i < 10; i++) {
            buttons[i].addActionListener(this);
            buttons[i].setFont(font);
            buttons[i].setFocusable(false);
        }

        equalB.setBounds(300, 100, 100, 100);
        addB.setBounds(300, 200, 100, 100);
        subB.setBounds(300, 300, 100, 100);
        delB.setBounds(100, 100, 100, 100);
        clearB.setBounds(0, 100, 100, 100);
        comaB.setBounds(200, 500, 100, 100);
        multiB.setBounds(300, 400, 100, 100);
        divB.setBounds(300, 500, 100, 100);
        pm.setBounds(200, 100, 100, 100);

        b0.setBounds(0, 500, 200, 100);
        b1.setBounds(0, 400, 100, 100);
        b4.setBounds(0, 300, 100, 100);
        b7.setBounds(0, 200, 100, 100);

        b2.setBounds(100, 400, 100, 100);
        b5.setBounds(100, 300, 100, 100);
        b8.setBounds(100, 200, 100, 100);

        b3.setBounds(200, 400, 100, 100);
        b6.setBounds(200, 300, 100, 100);
        b9.setBounds(200, 200, 100, 100);

        frame.add(delB);
        frame.add(clearB);
        frame.add(equalB);
        frame.add(comaB);
        frame.add(addB);
        frame.add(subB);
        frame.add(multiB);
        frame.add(divB);
        frame.add(pm);

        frame.add(b0);
        frame.add(b1);
        frame.add(b2);
        frame.add(b3);
        frame.add(b4);
        frame.add(b5);
        frame.add(b6);
        frame.add(b7);
        frame.add(b8);
        frame.add(b9);


        frame.setVisible(true);
    }

    public static void main(String[] args) {
        Calculator c = new Calculator();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (isFirstNumber) {
            for (JButton button : buttons) {
                if (e.getSource() == button) {
                    textField.setText(textField.getText() + button.getText());
                    num1 = Double.parseDouble(textField.getText());
                    System.out.println(num1);
                }
            }
        } else {
            for (JButton button : buttons) {
                if (e.getSource() == button) {
                    textField.setText(textField.getText() + button.getText());
                    num2 = Double.parseDouble(textField.getText());
                    System.out.println(num2);
                }
            }
        }

        if (e.getSource() == addB) {
            operator = '+';
            isFirstNumber = false;
            textField.setText("");
        } else if (e.getSource() == subB) {
            num1 = Double.parseDouble(textField.getText());
            operator = '-';
            isFirstNumber = false;
            textField.setText("");
        } else if (e.getSource() == multiB) {
            num1 = Double.parseDouble(textField.getText());
            operator = '×';
            isFirstNumber = false;
            textField.setText("");
        }else if (e.getSource() == divB) {
            num1 = Double.parseDouble(textField.getText());
            operator = '÷';
            isFirstNumber = false;
            textField.setText("");
        }else if (e.getSource() == pm) {
            num1 = Double.parseDouble(textField.getText());
            num1 = num1 * (-1);
            textField.setText(String.valueOf(num1));
            System.out.println(num1);
            isFirstNumber = false;
        }else if (e.getSource() == clearB) {
            textField.setText("");
            num1 = 0.0;
            num2 = 0.0;
            System.out.println(operator);
            isFirstNumber = true;
        } else if (e.getSource() == delB) {
            String currentText = textField.getText();
            if (isFirstNumber) {
                if (!currentText.isEmpty()) {
                    currentText = currentText.substring(0, currentText.length() - 1);
                    textField.setText(currentText);
                    num1 = Double.parseDouble(textField.getText());
                }
            } else {
                if (!currentText.isEmpty()) {
                    currentText = currentText.substring(0, currentText.length() - 1);
                    textField.setText(currentText);
                    num2 = Double.parseDouble(textField.getText());
                }
            }
        }
        else if (e.getSource() == comaB) {
            String currentText = textField.getText();
            if (currentText.isEmpty()) {
                currentText = "0.";
                for (JButton button : buttons) {
                    if (e.getSource() == button) {
                        textField.setText(textField.getText() + button.getText());
                    }
                }
            } else if (!currentText.contains(".")) {
                currentText += ".";
                for (JButton button : buttons) {
                    if (e.getSource() == button) {
                        textField.setText(textField.getText() + button.getText());
                    }
                }
            }
            textField.setText(currentText);
        }
        if (e.getSource() == equalB) {
            switch (operator) {
                case '+':
                    num1 = num1 + num2;
                    System.out.println(num1);
                    break;
                case '-':
                    num1 = num1 - num2;
                    System.out.println(num1);
                    break;
                case '÷':
                    num1 = num1 / num2;
                    System.out.println(num1);
                    break;
                case '×':
                    num1 = num1 * num2;
                    System.out.println(num1);
                    break;
            }
            textField.setText(String.valueOf(num1));
            isFirstNumber = true;
        }
    }
}
