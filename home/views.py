from django.http import HttpResponse
from django.shortcuts import render
from django.template import loader
import xml.etree.ElementTree as ET
from .models import functionScore

# Create your views here.

def index(request):
    return render(request, 'index.html')

def forms(request):
    return render(request, 'forms.html')

def dashboard(request):
    return render(request, 'dashboard.html')

def forgot_password(request):
    return render(request, 'forgot_password.html')

def tables(request):
    return render(request, 'tables.html')

def visual(request):
    return render(request, 'visualTest.html')

def d3test(request):
    return render(request, 'd3_test.html')

def report(request):
    return render(request, 'report.html')

def pullMetricFromXml(request):
    tree = ET.parse("/Users/jay/torch_5th/home/static/data/crulechk.0.xml")
    root = tree.getroot()


    all_functions = functionScore.objects.all()
    template = loader.get_template('d3_test.html')
    context = {
        'functionID': all_functions,
    }

    for child in root:
        print(child.tag)
        print(child.attrib)
    return HttpResponse(template.render(context, request))

