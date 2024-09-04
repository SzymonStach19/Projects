import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

public class RegisterPanel {

    public void RegisterPanel() {
        JFrame frame = new JFrame();
        frame.setTitle("Register");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setResizable(false);

        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(10, 10, 10, 10);
        gbc.fill = GridBagConstraints.HORIZONTAL;

        JLabel username = new JLabel("Name:");
        JTextField usernameT = new JTextField(20);
        JLabel usersurname = new JLabel("Surname:");
        JTextField usersurnameT = new JTextField(20);
        JLabel email = new JLabel("Email:");
        JTextField emailT = new JTextField(20);
        JLabel password = new JLabel("Password:");
        JPasswordField passwordT = new JPasswordField(20);

        gbc.gridx = 0;
        gbc.gridy = 0;
        panel.add(username, gbc);

        gbc.gridx = 1;
        panel.add(usernameT, gbc);

        gbc.gridx = 0;
        gbc.gridy = 1;
        panel.add(usersurname, gbc);

        gbc.gridx = 1;
        panel.add(usersurnameT, gbc);

        gbc.gridx = 0;
        gbc.gridy = 2;
        panel.add(email, gbc);

        gbc.gridx = 1;
        panel.add(emailT, gbc);

        gbc.gridx = 0;
        gbc.gridy = 3;
        panel.add(password, gbc);

        gbc.gridx = 1;
        panel.add(passwordT, gbc);

        JButton registerButton = new JButton("Sign Up");
        gbc.gridx = 0;
        gbc.gridy = 4;
        gbc.gridwidth = 2;
        panel.add(registerButton, gbc);

        registerButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String name = usernameT.getText();
                String surname = usersurnameT.getText();
                String email = emailT.getText();
                String password = new String(passwordT.getPassword());

                saveUserToDatabase(name, surname, email, password);
            }
        });

        frame.add(panel);
        frame.setVisible(true);
    }

    private void saveUserToDatabase(String name, String surname, String email, String password) {
        Connection conn = null;
        PreparedStatement pstmt = null;
        ResultSet rs = null;

        try {
            conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/MyDB", "root", "NewPassword");

            String checkEmailSql = "SELECT * FROM users WHERE email = ?";
            pstmt = conn.prepareStatement(checkEmailSql);
            pstmt.setString(1, email);
            rs = pstmt.executeQuery();

            if (rs.next()) {
                JOptionPane.showMessageDialog(null, "Email already exists!");
            } else {
                String insertUserSql = "INSERT INTO users (name, surname, email, password) VALUES (?, ?, ?, ?)";
                pstmt = conn.prepareStatement(insertUserSql);
                pstmt.setString(1, name);
                pstmt.setString(2, surname);
                pstmt.setString(3, email);
                pstmt.setString(4, password);

                int rowsInserted = pstmt.executeUpdate();

                if (rowsInserted > 0) {
                    JOptionPane.showMessageDialog(null, "User registered successfully!");
                }
            }
        } catch (SQLException ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(null, "Error registering user.");
        } finally {
            try {
                if (rs != null) rs.close();
                if (pstmt != null) pstmt.close();
                if (conn != null) conn.close();
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }
    }
}
