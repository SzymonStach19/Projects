import javax.swing.*;
import java.awt.Image;
import java.net.URL;

public class WeatherIcon extends JLabel {

    public static ImageIcon getIcon(String iconCode) {
        try {
            String iconUrl = "http://openweathermap.org/img/wn/" + iconCode + "@2x.png";
            URL url = new URL(iconUrl);
            ImageIcon originalIcon = new ImageIcon(url);

            Image scaledImage = originalIcon.getImage().getScaledInstance(120, 120, Image.SCALE_SMOOTH);
            return new ImageIcon(scaledImage);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }
}
