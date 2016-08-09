from django import forms

from .models import GitFile

class SignUpForm(forms.Form):
    email = forms.CharField(max_length=100)
    password = forms.CharField(max_length=100)

class FileForm(forms.Form):
    docfile = forms.FileField(
        label=''
    )


class GitFileForm(forms.Form):
    gitFile = forms.URLField(
        label='git url'
    )


class UploadFileForm(forms.Form):
     Lddfile = forms.FileField(
         label='Select a file'
     )

