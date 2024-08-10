import javax.swing.*;
import java.awt.*;

public class Text extends JTextField {

    public Text() {
        setSize(200,30);
        setBackground(new Color(255, 255, 255));
        setPreferredSize(new Dimension(300, 70));
        setHorizontalAlignment(JTextField.CENTER);
        setFont(new Font("Arial", Font.PLAIN, 42));
        setForeground(Color.BLACK);
        setBorder(null);
        setOpaque(true);
    }
}