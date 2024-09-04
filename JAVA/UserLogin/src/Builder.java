import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Builder {
    public Builder() {
        Window window = new Window();
        LoginPanel loginPanel = new LoginPanel();
        RegisterPanel registerPanel = new RegisterPanel();
        window.Frame();
        window.Panel();

        window.Button("Register", new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                window.Close();
                registerPanel.RegisterPanel();
            }
        });

        window.Button("Login", new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                window.Close();
                loginPanel.LoginPanel();
            }
        });
    }
}
