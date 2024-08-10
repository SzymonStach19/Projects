import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Window extends JFrame {

    private JLabel weatherIconLabel;

    public Window() {
        setSize(400, 250);
        setTitle("Weather");
        getContentPane().setBackground(new Color(221, 221, 221));

        setLayout(new BorderLayout());
        Panel panel = new Panel();
        add(panel, BorderLayout.CENTER);

        Text cityField = new Text();
        panel.add(cityField, BorderLayout.CENTER);

        Button searchButton = new Button();
        panel.add(searchButton);

        WeatherIcon weatherIcon = new WeatherIcon();
        panel.add(weatherIcon, BorderLayout.NORTH);

        Degrees degrees = new Degrees();
        panel.add(degrees, BorderLayout.SOUTH);

        searchButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String city = cityField.getText();
                double temperature = API.getTemperature(city);
                String iconCode = API.getIconCode(city);

                ImageIcon icon = WeatherIcon.getIcon(iconCode);
                weatherIcon.setIcon(icon);

                cityField.setText("");
                degrees.setText(Math.round(temperature) + "℃");

            }
        });

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
}
