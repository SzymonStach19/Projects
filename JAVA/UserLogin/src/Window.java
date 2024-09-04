import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;

public class Window {
    private JFrame frame;
    private JPanel panel;

    public void Frame() {
        frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(200, 70);
        frame.setLocationRelativeTo(null);
        frame.setResizable(false);
        frame.setBackground(new Color(255, 255, 255));
        frame.setVisible(true);
    }

    public void Panel() {
        panel = new JPanel();
        panel.setBounds(0, 0, 200, 700);
        panel.setBackground(new Color(0, 92, 92));
        frame.add(panel);
    }

    public void Button(String text, ActionListener actionListener) {
        JButton button = new JButton();
        button.setText(text);
        button.addActionListener(actionListener);
        panel.add(button);
        panel.revalidate();
    }

    public void Close(){
        frame.dispose();
    }
}