import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JPanel;
import javax.swing.Timer;


public class MapPanel extends JPanel{
	
	byte[][] grid;
	Image tileSet;
	
	int gridw;
	int gridh;
	int squarew;
	int squareh;
	
	int gridSquare = 30;
	
	Window parent;
	
	public MapPanel(int gridw, int gridh, int squarew, int squareh, Image tileSet, final Window parent) {
		this.parent = parent;
		this.gridw = gridw;
		this.gridh = gridh;
		this.squarew = squarew;
		this.squareh = squareh;
		
		Timer timer = new Timer(1000/60/*60 fps*/, new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				repaint();
			}
		});
		
		grid = new byte[gridh][gridw];
		for(int i=0; i<grid.length; i++) {
			for(int j=0; j<grid[i].length; j++) {
				grid[i][j] = 17;
			}
		}
		this.tileSet = tileSet;
		timer.start();
		
		this.addMouseListener(new MouseListener() {
			int x, y;
			@Override
			public void mouseClicked(MouseEvent e) {
				x = e.getX() / gridSquare;
				y = e.getY() / gridSquare;
				
				grid[y][x] = parent.getSelectedTile();
				System.out.println("Grid ("+x+","+y+") = "+grid[y][x]);
			}

			@Override
			public void mouseEntered(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mouseExited(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mousePressed(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}
			
		});
	}
	
	@Override
	public void paint(Graphics g) {
		for(int y=0; y<grid.length; y++) {
			for(int x=0; x<grid[0].length; x++) {
				GridPos pos = SelectionPanel.getGridPosision(grid[y][x], grid[y].length);
				pos.x = pos.x * squarew;
				pos.y = pos.y * squareh;
				g.drawImage(tileSet,
						x*gridSquare, y*gridSquare,
						(x+1)*gridSquare, (y+1)*gridSquare,
						pos.x, pos.y,
						pos.x+squarew, pos.y+squareh,
						null);
			}
		}
	}

	/**
	 * @return the grid
	 */
	public byte[][] getGrid() {
		return grid;
	}

	/**
	 * @param grid the grid to set
	 */
	public void setGrid(byte[][] grid) {
		this.grid = grid;
	}
}
