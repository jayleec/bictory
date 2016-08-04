from django.db import models

# Create your models here.

class User(models.Model):
    email = models.CharField(max_length=100)
    password = models.CharField(max_length=100)

    def __str__(self):
        return self.email

class functionScore(models.Model):
    funcID = models.CharField(max_length=5)
    score = models.FloatField(max_length=10)

class GitFile(models.Model):
    giturl = models.URLField(max_length=1000)
    gitFile = models.FileField(upload_to='Git/%Y/%m/%d')
    newFile = models.FilePathField(path='Git/%Y/%m/%d', recursive=True, )#default="null")

class Upload(models.Model):
    Lddfile = models.FileField(upload_to='Files/%Y/%m/%d')

    def __string__(self):
        return self.Lddfile
