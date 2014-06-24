import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JPanel;


public class SelectionPanel extends JPanel {
	
	Image tileSet;
	int gridWidth;
	int gridHeight;
	int squareWidth;
	int squareHeight;
	int tileWidth;
	int tileHeight;
	Window parent;
	
	public SelectionPanel(Image tileSet, final int gridWidth, int gridHeight,
			final int squareWidth, final int squareHeight, int tileWidth, int tileHeight, final Window parent) {
		setPreferredSize(new Dimension(500, 500));
		
		this.parent = parent;
		this.tileSet = tileSet;
		this.gridWidth = gridWidth;
		this.gridHeight = gridHeight;
		this.squareWidth = squareWidth;
		this.squareHeight = squareHeight;
		this.tileWidth = tileWidth;
		this.tileHeight = tileHeight;
		
		addMouseListener(new MouseListener() {
			int x, y;
			@Override
			public void mouseClicked(MouseEvent e) {
				x = e.getX() / squareWidth;
				y = e.getY() / squareHeight;
				parent.setSelectedTile(SelectionPanel.getTileID(x, y, gridWidth));
			}

			@Override
			public void mouseEntered(MouseEvent arg0) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mouseExited(MouseEvent arg0) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mousePressed(MouseEvent arg0) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mouseReleased(MouseEvent arg0) {
				// TODO Auto-generated method stub
				
			}
			
		});
	}
	
	@Override
	public void paint(Graphics g) {
		int srcx=0, srcy=0;
		int dstx=0, dsty=0;
		for(int y=0; y<gridHeight; y++) {
			for(int x=0; x<gridWidth; x++) {
				srcx = x * tileWidth;
				srcy = y * tileHeight;
				dstx = x * squareWidth;
				dsty = y * squareHeight;
				
				g.drawImage(tileSet,
						dstx, dsty,
						dstx+squareWidth, dsty+squareHeight,
						srcx, srcy, 
						srcx+tileWidth, srcy+tileHeight,
						null);
			}
		}
	}
	
	/**
	 * @return the tileSet
	 */
	public Image getTileSet() {
		return tileSet;
	}
	/**
	 * @param tileSet the tileSet to set
	 */
	public void setTileSet(Image tileSet) {
		this.tileSet = tileSet;
	}
	/**
	 * @return the gridWidth
	 */
	public int getGridWidth() {
		return gridWidth;
	}
	/**
	 * @param gridWidth the gridWidth to set
	 */
	public void setGridWidth(int gridWidth) {
		this.gridWidth = gridWidth;
	}
	/**
	 * @return the gridHeight
	 */
	public int getGridHeight() {
		return gridHeight;
	}
	/**
	 * @param gridHeight the gridHeight to set
	 */
	public void setGridHeight(int gridHeight) {
		this.gridHeight = gridHeight;
	}
	/**
	 * @return the squareWidth
	 */
	public int getSquareWidth() {
		return squareWidth;
	}
	/**
	 * @param squareWidth the squareWidth to set
	 */
	public void setSquareWidth(int squareWidth) {
		this.squareWidth = squareWidth;
	}
	/**
	 * @return the squareHeight
	 */
	public int getSquareHeight() {
		return squareHeight;
	}
	/**
	 * @param squareHeight the squareHeight to set
	 */
	public void setSquareHeight(int squareHeight) {
		this.squareHeight = squareHeight;
	}
	
	public static byte getTileID(int x, int y, int gridWidth) {
		return (byte) ((byte)x + y*gridWidth);
	}
	
	public static GridPos getGridPosision(byte id, int gridWidth) {
		int y = id / gridWidth;
		int x = id - y * gridWidth;
		return new GridPos(x, y);
	}
	
	
}
