import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Scanner;
import org.json.JSONObject;

public class API {

    private static String iconCode = "";
    private static double temperature = Double.NaN;

    public static double getTemperature(String city) {
        WeatherData(city);
        return temperature;
    }

    public static String getIconCode(String city) {
        WeatherData(city);
        return iconCode;
    }

    private static void WeatherData(String city) {
        HttpURLConnection connection = null;
        String api = "https://api.openweathermap.org/data/2.5/weather?q=" + city + ",PL&units=metric&lang=pl&appid=xxxxxx";

        try {
            URL url = new URL(api);
            connection = (HttpURLConnection) url.openConnection();
            connection.setRequestMethod("GET");
            connection.connect();

            int status = connection.getResponseCode();
            if (status == 200) {
                StringBuilder info = new StringBuilder();
                Scanner scanner = new Scanner(url.openStream());

                while (scanner.hasNextLine()) {
                    info.append(scanner.nextLine());
                }
                scanner.close();

                JSONObject jsonObject = new JSONObject(info.toString());

                temperature = jsonObject.getJSONObject("main").getDouble("temp");
                iconCode = jsonObject.getJSONArray("weather").getJSONObject(0).getString("icon");

            }

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (connection != null) {
                connection.disconnect();
            }
        }
    }
}
