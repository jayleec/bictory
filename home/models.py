from django.db import models

# Create your models here.


class functionScore(models.Model):
    funcID = models.CharField( max_length=5)
    score = models.FloatField(max_length=10)
