from django.shortcuts import render, HttpResponse

# Create your views here.

def index(request):
    print("Work Here!")
    return render(request, 'analyze/index.html')
