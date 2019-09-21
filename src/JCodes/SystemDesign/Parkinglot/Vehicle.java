package JCodes.SystemDesign.Parkinglot;


public class Vehicle {

    protected SpotSize spotSize;
    protected String licensePlate;

    public int spotsNeeded() {
        return spotSize.getSize();
    }

    public class MotorCycle extends Vehicle {
        public MotorCycle(String licensePlate) {

            this.licensePlate = licensePlate;
            this.spotSize = SpotSize.SMALL;
        }
    }

    public class Car extends Vehicle {
        public Car(String licensePlate) {
            this.licensePlate = licensePlate;
            this.spotSize = SpotSize.MEDIUM;
        }
    }

    public class Bus extends Vehicle {
        public Bus(String licensePlate) {
            this.licensePlate = licensePlate;
            this.spotSize = SpotSize.LARGE;
        }
    }
}
