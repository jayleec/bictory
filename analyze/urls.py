from django.conf.urls import patterns, url

from analyze import views

app_name = 'analyze'
urlpatterns = [
    url(r'^$', views.index, name='index'),
    url(r'^calculate/$', views.calculate, name='calculate'),
    url(r'^visualize/$', views.visualize, name='visualize'),
    url(r'^save/$', views.save, name='save'),
    url(r'^convert/$', views.convert, name='convert'),
]
