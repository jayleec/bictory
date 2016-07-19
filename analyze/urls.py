from django.conf.urls import patterns, url

from analyze import views

app_name = 'analyze'
urlpatterns = [
    url(r'^$', views.index, name='index'),
    # url(r'^dashboard/$', views.dashboard, name='dashboard'),
    url(r'^calculate/$', views.calculate, name='calculate'),
]
