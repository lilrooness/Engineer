import java.awt.BorderLayout;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JFrame;


public class Window extends JFrame{
	
	private byte selectedTile;
	MapPanel mapPanel;
	SelectionPanel selectionPanel;
	JButton save;
	
	public Window(int width, int height) {
		Image tileSet = null;
		selectedTile = 9;
		try {
			tileSet = ImageIO.read(new File("engineer_tileset.bmp"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(width, height);
		mapPanel = new MapPanel(16, 16, 16, 16, tileSet, this);
		selectionPanel = new SelectionPanel(tileSet, 16, 16, 30, 30, 16, 16, this);
		
		add(mapPanel, BorderLayout.CENTER);
		add(selectionPanel, BorderLayout.WEST);
		save = new JButton("Save");
		add(save, BorderLayout.SOUTH);
		save.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				saveMap("map.bin");
			}
			
		});
		setVisible(true);
	}

	/**
	 * @return the selectedTile
	 */
	public byte getSelectedTile() {
		return selectedTile;
	}

	/**
	 * @param selectedTile the selectedTile to set
	 */
	public void setSelectedTile(byte selectedTile) {
		this.selectedTile = selectedTile;
		System.out.println(selectedTile);
	}
	
	public void saveMap(String filename) {
		try {
			FileOutputStream out = new FileOutputStream(filename);
			ObjectOutputStream ob = new ObjectOutputStream(out);
			System.out.println("rows: "+mapPanel.getGrid().length+" cols: "+mapPanel.getGrid()[0].length);
			byte[] array = {(byte) mapPanel.getGrid().length, (byte) mapPanel.getGrid()[0].length};
			out.write(array);
			for(int y=0; y<mapPanel.getGrid().length; y++) {
				out.write(mapPanel.getGrid()[y]);
			}
			out.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
