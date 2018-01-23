import java.util.Vector;

public class Crane {

  private final Integer max_weight;

  private Boolean fragileLoad;

  private Container cargoForTransport;

  private Location destination;

  private int speed;

  public Boolean craneActivated;

    /**
   * 
   * @element-type Operator
   */
  public Vector  qualifiedFor;
    public Vector  myPort;
    public Vector  myCraneView;
    public Vector  myCraneController;

  public move(Location destination) {
  }

  public pickup(Container container) {
  }

  public void deliver() {
  }

  public Crane() {
  }

  public activate(Operator operator) {
  }

}