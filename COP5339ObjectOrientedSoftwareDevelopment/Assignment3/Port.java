import java.util.Vector;

/*
 * getInstance()
 */
public class Port {

  public Port thePort;

  public Integer location;

  public Integer newAttr;

    public Vector  loadUnload;
    /**
   * 
   * @element-type Operator
   */
  public Vector  myOperator;
    /**
   * 
   * @element-type Crane
   */
  public Vector  myCrane;
    /**
   * 
   * @element-type Warehouse
   */
  public Vector  myWarehouse;

  private Port() {
  }

  public void getInstance() {
  }

}