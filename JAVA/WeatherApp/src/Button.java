import javax.swing.*;
import java.awt.*;

public class Button extends JButton {

    public Button() {
        ImageIcon icon = new ImageIcon("/Users/szymon/Downloads/Lupa.png");

        Image scaledImage = icon.getImage().getScaledInstance(60, 60, Image.SCALE_SMOOTH);
        ImageIcon scaledIcon = new ImageIcon(scaledImage);
        setIcon(scaledIcon);

        setPreferredSize(new Dimension(80, 80));
    }
}