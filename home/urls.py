from django.conf.urls import url

from home import views

app_name = 'home'
urlpatterns = [
    url(r'^$', views.index, name='index'),
    url(r'^sign_up/$', views.sign_up, name='sign_up'),
    # url(r'^test/$', views.sign_up, name='sign_up'),
    url(r'^dashboard/$', views.dashboard, name='dashboard'),
    url(r'^tables/$', views.tables, name='tables'),
    url(r'^forms/$', views.forms, name='forms'),
    url(r'^report/$', views.report, name='report'),
    url(r'^forgot_password/$', views.forgot_password, name='forgot_password'),
    url(r'^visual/$', views.visual, name='visual'),
    url(r'^d3test/$', views.showScore, name='d3'),
    url(r'^test/$', views.test, name='test'),
    url(r'^convert/$', views.convert, name='convert'),
    url(r'^convert2/$', views.convert2, name='convert2'),
    url(r'^Wtree_test', views.Wtree_test, name='Wtree_test'),
]
