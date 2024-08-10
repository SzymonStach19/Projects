import javax.swing.*;
import java.awt.*;

public class Panel extends JPanel {
    public Panel() {
        setLayout(new FlowLayout());
        setBackground(Color.WHITE);
        setBackground(new Color(221, 221, 221));
        setPreferredSize(new Dimension(400, 80));
    }
}
