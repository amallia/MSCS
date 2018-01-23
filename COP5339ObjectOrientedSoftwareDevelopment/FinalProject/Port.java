import java.util.Vector;

public class Port {
  /* {author=Christopher Foley}*/


  private Port thePort;

  public final String portName;

    public Vector  myOperator;
    public Vector  myCrane;
    public Vector  myWarehouse;
    public Vector  employedBy;
    public Vector  contains;
    public Vector  has;
    public Vector  myShipStay;
    private static int cargoId = 1000;

  private Port() {
	  portName = "Last Port";
  }

  public Port getPort() { 
  if (thePort == null) thePort = new Port();
  return thePort;
  }

}