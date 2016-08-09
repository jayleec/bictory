# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('analyze', '0002_auto_20160804_0511'),
    ]

    operations = [
        migrations.AddField(
            model_name='function',
            name='function_id',
            field=models.CharField(max_length=10, default='1'),
            preserve_default=False,
        ),
    ]
