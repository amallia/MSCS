

import portDataBase;
public class ShipDbAdaptor {
  /* {author=Christopher Foley}*/
	
	


    public static portDataBase.VESSEL  myVESSELDB;

  public void createRecord(String name, String port) {
	  myVESSELDB.create(name, port);
	  
  }

  public void findShip(String name, String homePort) {
	  myVESSELDB.search(name, port);
  }

  public void readShipRecord() {
	  myVESSELDB.read();
 }
 

  public void writeShipRecords() {
	  myVESSELDB.write();
 }

  public void deleteShipRecord() {
	  myVESSELDB.delete();
 }

}