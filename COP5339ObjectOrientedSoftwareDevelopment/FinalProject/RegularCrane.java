public class RegularCrane extends Crane {

  private final boolean isFragile = false;

   public RegularCrane()
   {
	   super(30400);		// initialize to ISO intermodal maximum;
   }
    /**
   * 
   * @precondition craneMove: isFragile = false 
   */
  public void move() {
	  super.move();
  }

    /**
   * 
   * @precondition cranePickup: isFragile = false 
   */
  public void pickup() {
	  super.pickup();
  }

    /**
   * 
   * @precondition craneDeliver: isFragile = false 
   */
  public void deliver() {
	  super.deliver();
  }

}