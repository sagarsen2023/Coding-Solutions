
class Car:
  def __init__(self, make, model, year):
      self.make = make
      self.model = model
      self.year = year

  @property
  def make(self):
      return self._make

  @make.setter
  def make(self, value):
      self._make = value.upper()

  @property
  def model(self):
      return self._model

  @model.setter
  def model(self, value):
      self._model = value

  @property
  def year(self):
      return self._year

  @year.setter
  def year(self, value):
      self._year = value


if __name__ == "__main__":
  car = Car("Mercedes", "EQS 580", "2023")
  print("Make:", car.make)    
  print("Model:", car.model)  
  print("Year:", car.year)   

